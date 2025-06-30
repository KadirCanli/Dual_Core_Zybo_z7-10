# Usage with Vitis IDE:
# In Vitis IDE create a Single Application Debug launch configuration,
# change the debug type to 'Attach to running target' and provide this 
# tcl script in 'Execute Script' option.
# Path of this script: /home/blue/workspace/dual_arm2/core0_system/_ide/scripts/debugger_core0-default.tcl
# 
# 
# Usage with xsct:
# To debug using xsct, launch xsct and run below command
# source /home/blue/workspace/dual_arm2/core0_system/_ide/scripts/debugger_core0-default.tcl
# 
connect -url tcp:127.0.0.1:3121
targets -set -nocase -filter {name =~"APU*"}
loadhw -hw /home/blue/workspace/dual_arm2/design_1_wrapper/export/design_1_wrapper/hw/design_1_wrapper.xsa -mem-ranges [list {0x40000000 0xbfffffff}] -regs
configparams force-mem-access 1
targets -set -nocase -filter {name =~"APU*"}
stop
targets -set -nocase -filter {name =~ "*A9*#0"}
rst -processor
targets -set -nocase -filter {name =~ "*A9*#0"}
dow /home/blue/workspace/dual_arm2/core0/Debug/core0.elf
configparams force-mem-access 0
bpadd -addr &main
