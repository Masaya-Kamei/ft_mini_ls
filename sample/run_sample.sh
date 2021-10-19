#!/bin/zsh

cd ../
MINILS_PATH=`pwd`
TEST_DIR="${MINILS_PATH}/unit_tests/testdir"

make -C ${MINILS_PATH}
echo "\n---sample---"
cd ${TEST_DIR} && ${MINILS_PATH}/ft_mini_ls
