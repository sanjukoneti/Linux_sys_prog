cmd_/home/sanju/my_modules/major_minor_d/major_minor.mod := printf '%s\n'   major_minor.o | awk '!x[$$0]++ { print("/home/sanju/my_modules/major_minor_d/"$$0) }' > /home/sanju/my_modules/major_minor_d/major_minor.mod
