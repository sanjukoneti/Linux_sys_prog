cmd_/home/sanju/my_modules/Hello_World/modules.order := {   echo /home/sanju/my_modules/Hello_World/driver.ko; :; } | awk '!x[$$0]++' - > /home/sanju/my_modules/Hello_World/modules.order
