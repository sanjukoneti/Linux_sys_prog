/***************************************************************************//**
*  \file       driver.c
*
*  \details    dynamially  allocated the driver major and minor numbers
*
*  \author     Sanju
*
* *******************************************************************************/
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/kdev_t.h>

//creating dev with our custom major and minor number
dev_t dev=0;

/*
** Module Init function
*/
static int __init major_minor_static__init(void)
{
  //allocating the major number
   if((alloc_chrdev_region(&dev,0,1,"Ma_Mi_D")) <0)
   {
   pr_info("CanNONT ALLOCATE MAJOR NUMBER FOR DEVICE 1\n");
   return -1;
   }
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
MODULE_DESCRIPTION("A simple hello world driver(Dynamically allocating major and minor numbers)");
MODULE_VERSION("2:1.0");
