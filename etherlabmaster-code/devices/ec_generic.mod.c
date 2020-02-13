#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x28950ef1, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x98ab5c8d, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x9ed89edb, __VMLINUX_SYMBOL_STR(ecdev_open) },
	{ 0x9a19f23f, __VMLINUX_SYMBOL_STR(ecdev_withdraw) },
	{ 0x1ce449af, __VMLINUX_SYMBOL_STR(kernel_sendmsg) },
	{ 0x9e9390ec, __VMLINUX_SYMBOL_STR(sock_release) },
	{ 0x9b0c8220, __VMLINUX_SYMBOL_STR(_raw_read_lock) },
	{ 0x3894e347, __VMLINUX_SYMBOL_STR(dev_base_lock) },
	{ 0xa060d8b4, __VMLINUX_SYMBOL_STR(ether_setup_rh) },
	{ 0xc6804e1b, __VMLINUX_SYMBOL_STR(sock_create_kern) },
	{ 0xe453858e, __VMLINUX_SYMBOL_STR(ecdev_offer) },
	{ 0x343a1a8, __VMLINUX_SYMBOL_STR(__list_add) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x708b5f0c, __VMLINUX_SYMBOL_STR(free_netdev) },
	{ 0x9166fada, __VMLINUX_SYMBOL_STR(strncpy) },
	{ 0x521445b, __VMLINUX_SYMBOL_STR(list_del) },
	{ 0x8070df92, __VMLINUX_SYMBOL_STR(init_net) },
	{ 0x2d946b, __VMLINUX_SYMBOL_STR(ecdev_receive) },
	{ 0xf0fdf6cb, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0xb9b3895e, __VMLINUX_SYMBOL_STR(ecdev_set_link) },
	{ 0xf6122d1b, __VMLINUX_SYMBOL_STR(alloc_netdev_mqs) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0x41ec4c1a, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x36af3fad, __VMLINUX_SYMBOL_STR(kernel_recvmsg) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x7344a35a, __VMLINUX_SYMBOL_STR(kernel_bind) },
	{ 0x4ba24ffa, __VMLINUX_SYMBOL_STR(ecdev_close) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=ec_master";


MODULE_INFO(srcversion, "288D84E19A89DAD394C0D57");
MODULE_INFO(rhelversion, "7.7");
#ifdef RETPOLINE
	MODULE_INFO(retpoline, "Y");
#endif
#ifdef CONFIG_MPROFILE_KERNEL
	MODULE_INFO(mprofile, "Y");
#endif
