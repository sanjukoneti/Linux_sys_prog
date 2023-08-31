#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/kdev_t.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/device.h>
#include<linux/slab.h>
#include<linux/uaccess.h>


#define mem_size 1024

dev_t dev=0;
uint8_t *kernel_buffer;
static struct cdev my_cdev;
static struct class *dev_class;


static int __init chr_driver_init(void);
static void __exit chr_driver_exit(void);
static int my_open(struct inode *inode ,struct file *file);
static int my_release(struct inode *inode ,struct file *file);
static ssize_t my_read(struct file *filp ,char __user *buff ,size_t len ,loff_t *off);
static ssize_t my_write(struct file *filp ,const char  *buff ,size_t len ,loff_t *off);

static struct file_operations fops=
{
	.owner 		= THIS_MODULE,
	.read		= my_read,
	.write		= my_write,
	.open		= my_open,
	.release	= my_release,
};


static int __init chr_driver_init(void)
{
	/*Allocating Major Number*/
	if((alloc_chrdev_region(&dev ,0 ,1,"tg_my_dev")) <0)
	{
	 printk(KERN_INFO"Can not allocate the major number..\n");
	 return -1;
	}
	printk(KERN_INFO"Major=%d ,Minor=%d ..\n",MAJOR(dev) ,MINOR(dev));

	/*Create dev structure*/
	cdev_init(&my_cdev ,&fops);
	/*adding the character device to the system*/
	if((cdev_add(&my_cdev,dev,1) <0))
	{
	printk(KERN_INFO"can not add device to the system..\n");
	goto r_class;
	}
	
	/*creating struct class */
	if((dev_class=class_create(THIS_MODULE ,"my_class")) == NULL)
	{
	printk(KERN_INFO"can not create the struct class ..\n");
	goto r_class;
	}

	/*creating devicve*/
	if((device_create(dev_class,NULL,dev,NULL,"MY_DEVICE")) == NULL)
	{
	printk(KERN_INFO"can not create the Device ..\n");
	goto  r_device;
	}
	printk(KERN_INFO"Device driver insert....done properly ..\n");
	return 0;

	
r_class: 
	unregister_chrdev_region(dev,1);
	return -1;
r_device:
	class_destroy(dev_class);
	return -1;
}
static void __exit chr_driver_exit(void)
{
	device_destroy(dev_class,dev);
	class_destroy(dev_class);
	cdev_del(&my_cdev);
	unregister_chrdev_region(dev,1);
	printk(KERN_INFO"Device driver is removed successfully...\n");
}


static int my_open(struct inode *inode ,struct file *file)
{
  /*ctreating physical memory*/
 if((kernel_buffer = kmalloc(mem_size ,GFP_KERNEL)) == NULL)
 {

	printk(KERN_INFO"can not allocate the memory to the kernel buffer ..\n");
	return -1;
 }
	printk(KERN_INFO"Device file opened..\n");
	return 0;
 
}
	
	
static int my_release(struct inode *inode ,struct file *file)
{
	kfree(kernel_buffer);
	printk(KERN_INFO"Device File is Closed..\n");
	return 0;
}


static ssize_t my_read(struct file *filp ,char __user *buff ,size_t len ,loff_t *off)
{
	copy_to_user(buff ,kernel_buffer,mem_size);
	printk(KERN_INFO"Data Read:Done....\n");
	return mem_size;
}
static ssize_t my_write(struct file *filp ,const char  *buff ,size_t len ,loff_t *off)
{
	copy_from_user(kernel_buffer ,buff ,len);
	printk(KERN_INFO"Data is written successfully....\n");
	return len;
}

/*static int chr_driver_init(void);
static void chr_driver_exit(void);
static int chr_driver_init(void)
{
	printk("Inserted\n");
	return 0;
}

static void chr_driver_exit(void)
{
	printk("Exited\n");
}
*/
module_init(chr_driver_init);
module_exit(chr_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sanju konetisanju@gmail.com");
MODULE_DESCRIPTION("The character devoce driver from tg");
MODULE_VERSION("2:1.0");

