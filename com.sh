#!/bin/bash  
cd ./out

for file in *.c; do  
    if [ -f "$file" ]; then  
        filename=$(basename "$file" .c)
        echo "gcc -c -I/usr/local/include/ltsmin -std=c99 -fPIC \"$file\" "  
		gcc -g -c -I/usr/local/include/ltsmin -std=c99 -fPIC "$file"        
    fi  
done

for file in *.o; do
    if [ -f "$file" ]; then  
        filename=$(basename "$file" .o)
        echo "gcc -o \"$file.so\" \"$file\""  
		gcc -g -shared -o "$filename.so" "$file"        
    fi  
done