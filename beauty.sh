#!/bin/bash

dir="res_beauty"

if [ ! -d "$dir" ]
then
     mkdir "$dir"
fi

for i in *.c; do clang-format -style=file "$i" > "$dir/$i";done
for j in *.h; do clang-format -style=file "$j" > "$dir/$j";done
cd "$dir"
for k in *; do rm "../$k" && mv "$k" "../$k";done
cd ..
rmdir "$dir"
