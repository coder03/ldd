/* https://www.github.com/coder03/
31-03-2018
*/

before you compile this code you need a major no and minor no of the character driver.
Here, you have to create a device file under /dev
1. cat /proc/devices and pick an unused number under "Character devices:"
2. I am picking 300 as major no and 0 as minor no of the driver.
$mknod /dev/veda_cdrv c 300 0
$ls -l /dev/veda_cdrv

To remove driver and veda_cdrv device:
sudo rmmod char_driver_skel
sudo rm /dev/veda_cdrv
