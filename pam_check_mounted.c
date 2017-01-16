/* PAM intefaces provided */
#define PAM_SM_ACCOUNT
#define PAM_SM_AUTH
#define PAM_SM_SESSION

/* PAM hedaers */
#include </usr/include/security/pam_appl.h>
#include </usr/include/security/pam_modules.h>
#include <stdio.h>
#include <mntent.h> 
#include <string.h> 

/* Entry point for session creation */
int pam_sm_open_session(pam_handle_t *pamh, int flags, int argc, const char **argv) {
	return(PAM_IGNORE);
}

/* Entry point for session cleanup */
int pam_sm_close_session(pam_handle_t *pamh, int flags, int args, const char **argv) {
	return(PAM_IGNORE);
}

/* Entry point for accounting */
int pam_sm_acct_mgmt(pam_handle_t *pamh, int flags, int argc, const char **argv) {
	return(PAM_IGNORE);
}

/* Entry point for authentication verification */
int pam_sm_authenticate(pam_handle_t *pamh, int flags, int argc, const char **argv) {

	FILE * mtab = NULL; 
	struct mntent * part = NULL; 
	char * dev_path = "/dev/mount_point";
	
	if ((mtab = setmntent ("/etc/mtab", "r")) != NULL) { 
		while (( part = getmntent ( mtab )) != NULL) { 
			if (( part->mnt_fsname != NULL ) 
			&& ( strcmp ( part->mnt_fsname, dev_path )) == 0 ) { 
				printf("mount_point is mounted!\n");
		       	return(PAM_SUCCESS);	
			}else {
				printf("mount_point not mounted!\n");
				return(PAM_AUTH_ERR); /* you can send whatever PAM status code you want: linux.die.net/man/3/pam */ 
	       		}
		}
		endmntent (mtab);
	}
	return(PAM_IGNORE);
}

/* Entry point for setting user credentials (that is, to actually establish the authenticated user's credentials to the service provider) */
int pam_sm_setcred(pam_handle_t *pamh, int flags, int argc, const char **argv) {
	return(PAM_IGNORE);
}

/* Entry point for authentication token (password) changes */
int pam_sm_chauthtok(pam_handle_t *pamh, int flags, int argc, const char **argv) {
	return(PAM_IGNORE);
}
