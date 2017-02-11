find . -name '*.sh' | rev | cut -d '/' -f1 | cut -c4- | rev
