#!/bin/zsh

ESTATUS=0
cd ../
MINILS_PATH=`pwd`
TEST_PATH=(${MINILS_PATH} ${MINILS_PATH}/unit_tests/testdir)

# make address
echo "[Address Test]"
make -s -C $MINILS_PATH address
for T in ${TEST_PATH[@]}; do
	echo ${T}
	cd $T && diff <(${MINILS_PATH}/ft_mini_ls) <(/bin/ls -1tr)
	ESTATUS=$((ESTATUS|=$?))
done

echo

# make leak
echo "[Leak Test]"
make -s -C $MINILS_PATH leak
for T in ${TEST_PATH[@]}; do
	echo ${T}
	cd $T && diff <(${MINILS_PATH}/ft_mini_ls) <(/bin/ls -1tr)
	ESTATUS=$((ESTATUS|=$?))
done

echo

if [ $ESTATUS -eq 0 ]; then
	echo -e "[\e[32mOK\e[m]"
else
	echo -e "[\e[31mKO\e[m]"
fi
exit $ESTATUS
