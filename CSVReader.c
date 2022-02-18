//
//  Created by Hao Wu.
//

#include <stdio.h>
#include <string.h>
#include <mm_malloc.h>
#include <stdlib.h>
#include <math.h>

int main(){
    FILE *fp = NULL;
    char *line,*record;
    char buffer[10000];//这个数组大小也要根据自己文件的列数进行相应修改

    //输入文件路径
    //enter file path
    if((fp = fopen("/Users/.....", "rb")) != NULL)
    {
        //第0行开始
        //starting from line 0
        fseek(fp, 0, SEEK_SET);
        
        //当没有读取到文件末尾时循环继续
        //the loop continues when the end of the file is not read
        while ((line = fgets(buffer, sizeof(buffer), fp))!=NULL)
        {
            record = strtok(line, ",");
            
            //读取每一行的数据
            //read the data of each line
            while (record != NULL)
            {
                //将读取到的每一个数据打印出来
                //print every data
                printf("%s", record);
                record = strtok(NULL, "\n");
            }
        }
        fclose(fp);
        fp = NULL;
    }
}
