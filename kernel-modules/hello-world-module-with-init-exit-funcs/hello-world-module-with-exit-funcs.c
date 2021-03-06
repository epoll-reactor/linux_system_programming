/*
 * hello-world-module-with-exit-funcs.c - Demonstrating the module_init() and module_exit() macros.
 * This is preferred over using init_module() and cleanup_module().
 */
#include <linux/init.h>   // __init, __exit
#include <linux/kernel.h> // pr_info()
#include <linux/module.h> // module API

MODULE_LICENSE("GPL");

static int __init init_hello_world_module(void)
{
	pr_info("Hello world from module_init/cleanup.\n");

	/* A non 0 return means init_module failed; module can't be loaded. */
	return 0;
}

static void __init cleanup_hello_world_module(void)
{
	pr_info("Goodbye world from module_init/cleanup.\n");
}

module_init(init_hello_world_module);
module_exit(cleanup_hello_world_module);

