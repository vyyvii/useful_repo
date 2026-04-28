#! /bin/bash

success=0
fail=0
try=0

run_test()
{
    ((try++))
    name="$1"
    shift

    if eval "$@"; then
        echo "$name : TRUE"
        ((success++))
    else
        echo "$name : KO"
        ((fail++))
    fi
}

# EXAMPLES
# run_test "Help output" './functional_tests -h >/dev/null; [ \$? -eq 84 ]'
# run_test "Help output" 'diff <(./functional_tests -h) tests/answers/help >/dev/null'

# SCORE
score=$(( success * 100 / $try))
echo "Try: $try ; Successs: $success/$try ; Fails: $fail/$try ; Percent: $score%"
