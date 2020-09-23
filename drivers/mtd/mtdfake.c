/*
 * MTD Fake Symbol logger
 *
 * Copyright © 2007 Nokia Corporation. All rights reserved.
 *
 * Author: Richard Purdie <rpurdie@openedhand.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 *
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/console.h>
//#include <linux/vmalloc.h>
//#include <linux/workqueue.h>
//#include <linux/sched.h>
//#include <linux/wait.h>
//#include <linux/delay.h>
//#include <linux/interrupt.h>
//#include <linux/mtd/mtd.h>
#include <linux/kmsg_dump.h>

static int __init mtdfake_init(void)
{
	printk(KERN_INFO "mtdfake: fake symbols initiated\n");

	return 0;
}

void fv_mtd_only_erase(void)
{
	printk(KERN_ERR "fv_mtd_only_erase called ignoring\n");
}
EXPORT_SYMBOL(fv_mtd_only_erase);

static void __exit mtdoops_exit(void)
{
	printk(KERN_INFO "mtdfake: fake symbols destroyed\n");
}


module_init(mtdoops_init);
module_exit(mtdoops_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Protective Dad <protectivedad@nomail.com>");
MODULE_DESCRIPTION("MTD fake symbols console logger/driver");
