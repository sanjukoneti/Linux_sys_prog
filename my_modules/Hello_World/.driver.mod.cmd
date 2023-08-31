cmd_/home/sanju/my_modules/Hello_World/driver.mod := printf '%s\n'   driver.o | awk '!x[$$0]++ { print("/home/sanju/my_modules/Hello_World/"$$0) }' > /home/sanju/my_modules/Hello_World/driver.mod
