#!/usr/bin/env bash
set -euo pipefail

BRANCH="${1:-main}"

while true; do
    read -rp "Messaggio di commit: " commit_msg

    if [ -z "$commit_msg" ]; then
        echo "Il messaggio non può essere vuoto."
        continue
    fi

    read -rp "Confermi il messaggio: \"$commit_msg\"? [s/N] " confirm
    case "$confirm" in
        [sS]|[sS][iI])
            break
            ;;
        *)
            echo "Ok, reinserisci il messaggio."
            ;;
    esac
done

git add .
git commit -m "$commit_msg"
git push -u origin "$BRANCH"