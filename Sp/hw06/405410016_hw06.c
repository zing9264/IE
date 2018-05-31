/*
listDir.c
usage listDir .
*/
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <linux/limits.h>
#include <sys/inotify.h>
#include <unistd.h>


#define BUF_LEN (10 * (sizeof(struct inotify_event) + NAME_MAX + 1))

int level = 0;

void printInotifyEvent(struct inotify_event* event);

char wd[1000][10000];
int fd;
void printName(char* type, char* name) {
    printf("%s", type);
    for (int i=0; i < level; i++)
        printf("  ");
    if (strcmp("d", type)==0)
        printf("+");
    else
        printf("|");
    printf("%s\n", name);
}

void listDir(char* pathName)
{
    int ret1;
   
	ret1=inotify_add_watch(fd,pathName, IN_ALL_EVENTS);
	strcpy(wd[ret1],pathName);

    level++;
    DIR* curDir = opendir(pathName);
    assert(curDir!=NULL);
    char* newPathName = (char*)malloc(PATH_MAX);
    struct dirent entry;
    struct dirent* result;
    int ret;
    ret = readdir_r(curDir, &entry, &result);
    while(result != NULL) {
        if (strcmp(entry.d_name, ".") == 0 || strcmp(entry.d_name, "..") == 0) {
            ret = readdir_r(curDir, &entry, &result);
            assert(ret == 0);
            continue;
        }
        assert(ret == 0);
        if (entry.d_type == DT_LNK)
            printName("Link", entry.d_name);
        if (entry.d_type == DT_REG)
            printName("File", entry.d_name);
        if (entry.d_type == DT_DIR) {
            printName("Dir ", entry.d_name);
            sprintf(newPathName,"%s/%s", pathName, entry.d_name);
            printf("%s\n", newPathName);
            listDir(newPathName);
        }
        ret = readdir_r(curDir, &entry, &result);
        assert(ret == 0);        
    }
    closedir(curDir);
    level--;
}


int main(int argc, char **argv) {
	int num, ret, i;
	char* p;
	char inotify_entity[BUF_LEN];
     fd = inotify_init();
    listDir("./");

	while(1) {
		num = read(fd, inotify_entity, BUF_LEN);
		for (p = inotify_entity; p < inotify_entity + num; ) {
			printInotifyEvent((struct inotify_event *) p);
			p+=sizeof(struct inotify_event) + ((struct inotify_event *)p)->len;
		}
	}
}

void printInotifyEvent(struct inotify_event* event) {
	char buf[4096]="";
	sprintf(buf, "[%s] ", wd[event->wd]);
	strncat(buf, "{", 4096);
	if (event->mask & IN_ACCESS) 		strncat(buf,"讀取檔案, ", 4096);
	if (event->mask & IN_ATTRIB) 		strncat(buf,"檔案屬性變更, ", 4096);
	if (event->mask & IN_CLOSE_WRITE) 	strncat(buf,"被開啟為「可寫入」的檔案遭關閉, ", 4096);
	if (event->mask & IN_CLOSE_NOWRITE) 	strncat(buf,"被開啟為「非寫入」的檔案遭關閉, ", 4096);
	if (event->mask & IN_CREATE) 		strncat(buf,"監控中的目錄下有新檔案產生, ", 4096);
	if (event->mask & IN_DELETE) 		strncat(buf,"檔案或目錄被刪除, ", 4096);
	if (event->mask & IN_DELETE_SELF) 	strncat(buf,"監控中的檔案遭刪除, ", 4096);
	if (event->mask & IN_MODIFY) 		strncat(buf,"檔案被修改, ", 4096);
	if (event->mask & IN_MOVE_SELF)		strncat(buf,"監控中的文件或目錄移動, ", 4096);
	if (event->mask & IN_MOVED_FROM)	strncat(buf,"檔案被移出, ", 4096);
	if (event->mask & IN_MOVED_TO)		strncat(buf,"檔案被移入, ", 4096);
	if (event->mask & IN_OPEN)		strncat(buf,"檔案被開啟, ", 4096);
	if (event->mask & IN_IGNORED)		strncat(buf,"文件被删除或者文件系統被umount, ", 4096);
	if (event->mask & IN_ISDIR)		strncat(buf,"目錄, ", 4096);
	if (event->mask & IN_Q_OVERFLOW)	strncat(buf,"佇列溢出, ", 4096);
	buf[strlen(buf)-2]='\0';
	strncat(buf, "}", 4096);
	sprintf(buf, "%s cookie = %d", buf, event->cookie);
	if (event->len>0)
    	sprintf(buf, "%s filename = %s\n", buf, event->name);
	else
		sprintf(buf, "%s  filename = null\n", buf);
	printf("%s", buf);
}
