#!/bin/bash

targets=("myvec_tests" "myvec_tests_asan")
labels=("normal" "asan")
tests=("push_pop_test" "size_test" "resize_test" "clear_test" "empty_test")
declare -A test_points=(
    ["push_pop_test"]=40
    ["size_test"]=20
    ["resize_test"]=20
    ["clear_test"]=10
    ["empty_test"]=10
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
        echo -ne "Running $test_name with label $label, epoch $epoch...\t"
        if ! ctest -Q -R "${test_name}" -L "${label}" --output-on-failure; then
            echo -e "\033[0;31mfailed\033[0m"
            ctest -R "${test_name}" -L "${label}" --output-on-failure
            return 0
        else
            echo -e "\033[0;32mpassed\033[0m"
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
            break 2
        fi
    done
    total_score=$((total_score + test_points[$test_name]))
done

echo "Total score: $total_score/$max_score"
