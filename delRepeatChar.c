/* 本程序是将字符串中重复的字符删除
 * 例： abccbd  -> ad
 *      abccbd 删除cc, 得到 abbd； 再删除 bb, 得到 ad
 * 
 * 分析：使用栈来进行处理，原始串的首字符先入结果栈（初始状态），
 *      从原始串的第二个字符开始，遍历原始串中剩余的每一个字符；
 *          若与结果栈的栈顶相同，则处理原始串的下一个字符，同时置1重复标志；
 *          若与结果栈的栈顶不同，且重复标志没有被置1，入栈，处理原始串的字符；
 *          若与结果栈的栈顶不同，但重复标志被置1，那么结果栈弹栈（相当于将已经压栈的重复的字符在结果栈中删除），且下一轮处理使用相同的原始串字符进行处理；
 */

#include <stdio.h>

static void PrintString(char *str, int length)
{
    int i;
    for (i = 0; i < length; i++) {
        printf("str[%d]:%c\n", i, *(str + i));
    }
}

char *DelRepeatChar(char *str, int length)
{
    if (str == NULL || length <= 0) {
        return NULL;
    }

    if (length == 1) {
        return str;
    }

    char *dst = (char *)malloc(sizeof(char) * length);
    if (dst == NULL) {
        return NULL;
    }
    memset(dst, 0, sizeof(char) * length);

    printf("\ninput str, length:%d\n", length);
    PrintString(str, length);

    int strIdx = 1;
    int dstIdx = 1;
    int delFlag = 0;
    char delChar = '0';
    *(dst) = *str;

    while (strIdx < length) {
        // printf("\n\ncur str char:%c\n", *(str + strIdx));
        // PrintString(dst, dstIdx);

        if (*(str + strIdx) == *(dst + dstIdx - 1)) {
            delFlag = 1;
            delChar = *(str + strIdx);
            strIdx++;
            // printf("same continue\n");
            continue;
        }

        if (delFlag != 1) {
            *(dst + dstIdx) = *(str + strIdx);
            dstIdx++;
            strIdx++;
        } else {
            dstIdx--;
            delFlag = 0;
        }
    }

    printf("\nresult:%d\n", dstIdx);
    PrintString(dst, dstIdx);

    return dst;
}

int main()
{    
    printf("###############################\n");
    char a1[] = "abccbd";
    char *dst = DelRepeatChar(a1, 6);
    if (dst != NULL) {
        free(dst);
        dst = NULL;
    }

    printf("###############################\n");
    char a2[] = "abcccbd";
    dst = DelRepeatChar(a2, 7);
    if (dst != NULL) {
        free(dst);
        dst = NULL;
    }

    printf("###############################\n");
    char a3[] = "abcccbcd";
    dst = DelRepeatChar(a3, 8);
    if (dst != NULL) {
        free(dst);
        dst = NULL;
    }

    printf("###############################\n");
    char a4[] = "abcccbbcd";
    dst = DelRepeatChar(a4, 9);
    if (dst != NULL) {
        free(dst);
        dst = NULL;
    }

    printf("###############################\n");
    char a5[] = "cbbccddc";
    dst = DelRepeatChar(a5, 8);
    if (dst != NULL) {
        free(dst);
        dst = NULL;
    }

    printf("###############################\n");
    char a6[] = "bbccddc";
    dst = DelRepeatChar(a6, 7);
    if (dst != NULL) {
        free(dst);
        dst = NULL;
    }

    return 0;
}
