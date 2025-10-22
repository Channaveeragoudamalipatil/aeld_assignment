#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <syslog.h>
#include <fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    const char* FilePath = argv[1];
    const char* msg= argv[2];

    openlog("writer", LOG_PID, LOG_USER);
    if(argc!=3)
    {
        syslog(LOG_ERR,"invalied num of arguments: %d",argc);
        fprintf(stderr, "Error: invalied num of arguments");
        return 1;
    }
    else
    {
        int fd=open(FilePath, O_WRONLY|O_CREAT|O_TRUNC, 0644);
        if(fd==-1)
        {
            syslog(LOG_ERR,"Unable to open the file");
            fprintf(stderr, "Unable to open the file" );
            return 1;
        }
        else
        {
            if(write(fd, msg, strlen(msg))== -1)
            {
                syslog(LOG_ERR, "unable to write the data into file");
                fprintf(stderr,"unable to write the data into file");
                return 1;
            }
            else
            {
                syslog(LOG_DEBUG,"Data written sucessfully");
                fprintf(stdout,"sucessfully written the data into the file");
            }
        }
    }
    closelog();
    return 0;
}