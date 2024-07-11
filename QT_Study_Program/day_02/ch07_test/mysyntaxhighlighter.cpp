#include "mysyntaxhighlighter.h"

MySyntaxHighlighter::MySyntaxHighlighter(QTextDocument *parent) : QSyntaxHighlighter (parent)
{

}

void MySyntaxHighlighter::highlightBlock(const QString &text)           //高亮文本块
{
    QTextCharFormat myFormat;                                           //字符格式
    myFormat.setFontWeight(QFont::Bold);
    myFormat.setForeground(Qt::green);
    QString pattern = "\\bchar\\b";
    QRegExp expression(pattern);                                        //创建正则
    int index = text.indexOf(expression);
    while(index >= 0){
        int length = expression.matchedLength();
        setFormat(index, length, myFormat);
        index = text.indexOf(expression, index + length);
    }
}
