#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/usb.h>
#include<linux/init.h>
#include<linux/cdev_t.h>
#include<linux/fs.h>
#include<linux/uaccess.h>
#include<linux/stdlib.h>


//macros for product ID nad Vendor ID

#define USB_PRODUCT_ID  0x8816
#define USB_VENDOR_ID   0x4999

static int __init usb_loading(void);
static void __exit usb_unloading(void);

static struct usb_driver usb_drv_struct=
{
	.name		= "Sanju_sub_driver",
	.id_table  	= uab_drv_table,
	.probe  	= usb_probe,
	.disconect	= usb_disconect,
};

static struct file_operations fops=
{
	.owner		= THIS_MODULE,
	.read		= my_read,
	.write		= my_write,
	.open		= my_open,
	.release	= my_release,
};

static int __init usb_loading(void)
{
	usb_register(&usb_drv_struct);
}

static void __exit usb_unloading(void)
{
	usb_unregister(&usb_drv_struct);
}

static struct usb_device_id usb_table[] =
{
	USB_DEVICE(USB_VENDOR_ID,USB_PRODUCT_ID);
}

MODULE_DEVICE_TABLE(usb,usb_table);


static struct usb_probe(struct usb_Interface *interface ,const        device_id *id)
{




						
