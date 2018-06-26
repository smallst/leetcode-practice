cat words.txt|sed -r "s/\s+/\n/g"|sed -r '/^$/d'|sort|uniq -c|sort -rn|awk '{print $2 " " $1}'
