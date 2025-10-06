#!/bin/bash

start_date="2025-10-06"
end_date="2025-11-08"

current="$start_date"

while [ "$current" != "$(date -I -d "$end_date + 1 day")" ]; do
    echo "Processing $current..."

    commit_count=$((RANDOM % 3 + 5))

    for ((i=1; i<=commit_count; i++)); do
        echo "Commit on $current" >> commit-log.txt
        git add .

        git commit -m "Daily auto commit $i on $current" --date="$current 10:0$i:00"
    done

    current=$(date -I -d "$current + 1 day")
done

git push origin main
