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
	{ 0xc0b7368f, __VMLINUX_SYMBOL_STR(ecrt_master_receive) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0x8b44ae18, __VMLINUX_SYMBOL_STR(ecrt_master_create_domain) },
	{ 0x1ceca9c3, __VMLINUX_SYMBOL_STR(ecrt_master_send) },
	{ 0x8eff0978, __VMLINUX_SYMBOL_STR(ecrt_domain_queue) },
	{ 0xa08bd73d, __VMLINUX_SYMBOL_STR(ecrt_master_send_ext) },
	{ 0x593a99b, __VMLINUX_SYMBOL_STR(init_timer_key) },
	{ 0x41f67e04, __VMLINUX_SYMBOL_STR(ecrt_domain_reg_pdo_entry_list) },
	{ 0x7d11c268, __VMLINUX_SYMBOL_STR(jiffies) },
	{ 0xdb11300, __VMLINUX_SYMBOL_STR(ecrt_domain_process) },
	{ 0x7725336f, __VMLINUX_SYMBOL_STR(ecrt_domain_state) },
	{ 0xd5f2172f, __VMLINUX_SYMBOL_STR(del_timer_sync) },
	{ 0x1a751538, __VMLINUX_SYMBOL_STR(ecrt_master_callbacks) },
	{ 0x50a00e0, __VMLINUX_SYMBOL_STR(ecrt_master_state) },
	{ 0x5e933285, __VMLINUX_SYMBOL_STR(ecrt_slave_config_state) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xd4d13426, __VMLINUX_SYMBOL_STR(ecrt_master_slave_config) },
	{ 0x68aca4ad, __VMLINUX_SYMBOL_STR(down) },
	{ 0xbe2c0274, __VMLINUX_SYMBOL_STR(add_timer) },
	{ 0x7217f131, __VMLINUX_SYMBOL_STR(ecrt_slave_config_pdos) },
	{ 0xe0537c6b, __VMLINUX_SYMBOL_STR(ecrt_domain_external_memory) },
	{ 0xf0fdf6cb, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0xbece8ead, __VMLINUX_SYMBOL_STR(ecrt_domain_size) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x11a27752, __VMLINUX_SYMBOL_STR(ecrt_master_activate) },
	{ 0xb8e61231, __VMLINUX_SYMBOL_STR(ecrt_release_master) },
	{ 0x71e3cecb, __VMLINUX_SYMBOL_STR(up) },
	{ 0x66235f3a, __VMLINUX_SYMBOL_STR(ecrt_request_master) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=ec_master";


MODULE_INFO(srcversion, "7D79A65FE0B0BD05CFF427C");
MODULE_INFO(rhelversion, "7.7");
#ifdef RETPOLINE
	MODULE_INFO(retpoline, "Y");
#endif
#ifdef CONFIG_MPROFILE_KERNEL
	MODULE_INFO(mprofile, "Y");
#endif
