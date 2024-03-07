#!/bin/bash

read -p "EJEC NAME: " project_name

project_name=${project_name// /_}

touch "$project_name".c

main="#include<stdio.h>
\n
\nint main (void){\n\t\n\treturn 0;\n}"

echo -e $main > "$project_name".c