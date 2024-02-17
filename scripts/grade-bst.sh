#!/bin/bash

targets=("bst_tests" "bst_tests_asan")
labels=("normal" "asan")
tests=("preorder_test" "traversal_crosstest" "stress_test" "log_test")
declare -A test_points=(
    ["preorder_test"]=20
    ["traversal_crosstest"]=20
    ["stress_test"]=20
    ["log_test"]=40
)
test_epoch=5
max_score=100
total_score=0

cmake -S . -B build
echo "Start building..."
for target in "${targets[@]}"; do
    echo "Building ${target}..."
    if ! cmake --build build --target $target -- -j $(nproc); then
        echo "Compilation failed for $target."
        echo "Total score: 0/$max_score"
        exit 1
    fi
done
echo "Build complete."

run_test() {
    local test_name=$1
    local label=$2
    local points=$3
    for (( epoch=1; epoch<=test_epoch; epoch++ )); do
        echo "Running $test_name with label $label, epoch $epoch..."
        echo "ctest -R \"${test_name}\" -L \"${label}\" --output-on-failure"
        if ! ctest -R "${test_name}" -L "${label}" --output-on-failure; then
            echo "$test_name failed with label $label."
            return 0
        fi
    done
    return 1
}

cd build
for test_name in "${tests[@]}"; do
    for label in "${labels[@]}"; do
        run_test $test_name $label ${test_points[$test_name]}
        if [ $? -eq 0 ]; then
            echo "Stopping further tests."
            total_score=$((total_score - test_points[$test_name]))
            break 2
        fi
    done
    total_score=$((total_score + test_points[$test_name]))
done

echo "Total score: $total_score/$max_score"
