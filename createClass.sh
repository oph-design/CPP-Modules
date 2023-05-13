uppercaseName=$(printf '%s' "$1" | tr "a-z" "A-Z" )
# hpp file

echo "#ifndef ${uppercaseName}_H" > $PWD/$1.hpp
echo "# define ${uppercaseName}_H" >> $PWD/$1.hpp

echo "# include <iostream>" >> $PWD/$1.hpp
echo "# include <string>" >> $PWD/$1.hpp

echo "" >> $1.hpp

echo "class $1\n{" >> $PWD/$1.hpp

printf "\tprivate:\n" >> $PWD/$1.hpp
c=1
for i in "${@:2}"; do
    if [ $((c%2)) -eq 0 ]
    then
        echo "\t_$i;" >> $PWD/$1.hpp
    else
        printf "\t\t$i" >> $PWD/$1.hpp
    fi
    c=$((c+1))
done
echo "" >> $PWD/$1.hpp
printf "\tpublic:\n" >> $PWD/$1.hpp
printf "\t\t$1(void);\n" >> $PWD/$1.hpp
printf "\t\t$1(const $1 &rhs);\n" >> $PWD/$1.hpp
if [ $# -gt 2 ]
then
	printf "\t\t$1(" >> $PWD/$1.hpp
	for i in "${@:2}"; do
		if [ $((c%2)) -eq 0 ]
		then
			j="$(tr "a-z" "A-Z" <<< ${i:0:1})${i:1}"
			printf "${prev} new$j" >> $PWD/$1.hpp
			if [ $i != ${!#} ]
			then
				printf ", " >> $PWD/$1.hpp
			else
				printf ");\n" >> $PWD/$1.hpp
			fi
		else
			prev=$i
		fi
		c=$((c+1))
	done
fi
printf "\t\t~$1(void);\n" >> $PWD/$1.hpp
printf "\t\t$1& operator=(const $1 &rhs);\n" >> $PWD/$1.hpp

for i in "${@:2}"; do
    if [ $((c%2)) -eq 0 ]
    then
		j="$(tr "a-z" "A-Z" <<< ${i:0:1})${i:1}"
        echo "$j(void) const;" >> $PWD/$1.hpp
    else
        printf "\t\t$i get" >> $PWD/$1.hpp
    fi
    c=$((c+1))
done

for i in "${@:2}"; do
    if [ $((c%2)) -eq 0 ]
    then
		j="$(tr "a-z" "A-Z" <<< ${i:0:1})${i:1}"
        printf "\t\tvoid set$j(${prev} _$i);\n" >> $PWD/$1.hpp

    else

        prev=$i

    fi
    c=$((c+1))
done

printf "\t\tvoid output(void);\n" >> $PWD/$1.hpp

echo "};" >> $PWD/$1.hpp

echo "" >> $PWD/$1.hpp

echo "#endif" >> $PWD/$1.hpp

# cpp file
echo "#include \"$1.hpp\"\n" > $1.cpp
echo "$1::$1(void)" >> $PWD/$1.cpp
printf "\t: " >> $PWD/$1.cpp
for i in "${@:2}"; do
    if [ $((c%2)) -eq 0 ]
    then
        printf "_$i(0)" >> $PWD/$1.cpp
		if [ $i != ${!#} ]
		then
			printf ", " >> $PWD/$1.cpp
		fi
    fi
    c=$((c+1))
done

echo "\n{\n\n}" >> $PWD/$1.cpp

echo "" >> $PWD/$1.cpp

echo "$1::$1(const $1& rhs)" >> $PWD/$1.cpp
echo "{" >> $PWD/$1.cpp
echo "\t*this = rhs;" >> $PWD/$1.cpp
echo "}" >> $PWD/$1.cpp

echo "" >> $PWD/$1.cpp

if [ $# -gt 2 ]
	then
		printf "$1::$1(" >> $PWD/$1.cpp
		for i in "${@:2}"; do
			if [ $((c%2)) -eq 0 ]
			then
				j="$(tr "a-z" "A-Z" <<< ${i:0:1})${i:1}"
				printf "${prev} new$j" >> $PWD/$1.cpp
				if [ $i != ${!#} ]
				then
					printf ", " >> $PWD/$1.cpp
				else
					printf ")\n\t: " >> $PWD/$1.cpp
				fi
			else
				prev=$i
			fi
			c=$((c+1))
		done
		for i in "${@:2}"; do
			if [ $((c%2)) -eq 0 ]
			then
				j="$(tr "a-z" "A-Z" <<< ${i:0:1})${i:1}"
				printf "_$i(new$j)" >> $PWD/$1.cpp
				if [ $i != ${!#} ]
				then
					printf ", " >> $PWD/$1.cpp
				else
					printf "\n{\n\n}\n\n" >> $PWD/$1.cpp
				fi
			else
				prev=$i
			fi
			c=$((c+1))
		done
fi

echo "$1::~$1(void)\n{" >> $PWD/$1.cpp
echo "" >> $PWD/$1.cpp
echo "}\n" >> $PWD/$1.cpp

echo "$1&\t$1::operator=(const $1& rhs)\n{" >> $PWD/$1.cpp
echo "\treturn *this;" >> $PWD/$1.cpp
echo "}\n" >> $PWD/$1.cpp

for i in "${@:2}"; do
    if [ $((c%2)) -eq 0 ]
    then
		j="$(tr "a-z" "A-Z" <<< ${i:0:1})${i:1}"
        echo "$prev $1::get$j(void) const\n{\n\treturn _$i;\n}" >> $PWD/$1.cpp


    else

        prev=$i
    fi
    c=$((c+1))
done

echo "" >> $PWD/$1.cpp
for i in "${@:2}"; do
    if [ $((c%2)) -eq 0 ]
    then
		j="$(tr "a-z" "A-Z" <<< ${i:0:1})${i:1}"
        echo "void $1::set$j($prev new$j)\n{\n\t_$i = new$j;\n}" >> $PWD/$1.cpp

    else

        prev=$i
    fi
    c=$((c+1))
done

echo "" >> $PWD/$1.cpp
echo "void $1::output(void)\n{" >> $PWD/$1.cpp

for i in "${@:2}"; do
    if [ $((c%2)) -eq 0 ]
    then
        echo "	std::cout << \"$i : \" << _$i << std::endl;" >> $PWD/$1.cpp
    fi
    c=$((c+1))
done

echo "}" >> $PWD/$1.cpp

echo "" >> $PWD/$1.cpp

