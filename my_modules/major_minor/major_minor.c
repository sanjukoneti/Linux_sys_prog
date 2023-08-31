/***************************************************************************//**
*  \file       driver.c
*
*  \details    statically allocated the driver major and minor numbers
*
*  \author     Sanju
*
* *******************************************************************************/
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>


//creating dev with our custom major and minor number
dev_t dev=MKDEV(300,0);





/*
** Module Init function
*/
static int __init major_minor_static__init(void)
{
   register_chrdev_region(dev,1,"Sanju_Dev");
   pr_info("Major =%d Minor =%d \n",MAJOR(dev), MINOR(dev));
   pr_info("Kernel Module Inserted Successfully...\n");
    return 0;
}

/*
** Module Exit function
*/
static void __exit major_minor_static__exit(void)
{
    unregister_chrdev_region(dev,1);
    pr_info("Kernel Module Removed Successfully...\n");
}
 
module_init(major_minor_static__init);
module_exit(major_minor_static__exit);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sanju <sanjukoneti@gmail.com>");
MODULE_DESCRIPTION("A simple hello world driver(statically allocating major and minor numbers)");
MODULE_VERSION("2:1.0");
