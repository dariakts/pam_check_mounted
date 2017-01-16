# pam_check_mounted

Basic PAM module that checks if a volume is mounted during login. It will display an error message and deny login if not. 

### To compile:

`gcc -fPIC -DPIC -shared -rdynamic -o pam_check_mounted.so pam_check_mounted.c`

### To install:

`cp pam_ignore.so /lib/security/pam_check_mounted.so`

`chown root:root /lib/security/pam_check_mounted.so`

`chmod 755 /lib/security/pam_check_mounted.so`

### To enable:

In `/etc/pam.d/common-auth` add this line:

`auth requisite pam_check_mounted.so`

### Resources:

O'Reilly guides:

[Writing PAM Modules, Part One] (http://www.linuxdevcenter.com/pub/a/linux/2002/05/02/pam_modules.html)

[Writing PAM Modules, Part Two] (http://www.linuxdevcenter.com/pub/a/linux/2002/05/23/pam_modules.html)

[Writing PAM Modules, Part Three] (http://www.linuxdevcenter.com/pub/a/linux/2002/05/30/pam_modules.html)
