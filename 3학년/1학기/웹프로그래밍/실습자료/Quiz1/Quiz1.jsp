<%@ page contentType="text/html;charset=euc-kr" %>

<HTML>
<HEAD>
<TITLE> Quiz 1 - �ڷ��� ��ȯ </TITLE>
</HEAD>
<BODY>

<%
// ���� ����
String strNum;
int intNum;
double dblNum;
float fltNum;
byte bytNum;
    
strNum = "1";

// �� String���� Integer������ ��ȯ
intNum = Integer.parseInt(strNum);
    
// �� String���� Double������ ��ȯ
dblNum = Double.parseDouble(strNum);
    
// �� String���� Byte������ ��ȯ
bytNum = Byte.parseByte(strNum);
%>

<%-- ��ȯ ��� ��� --%>
String : <%=strNum %><BR>
�� Integer : <%=intNum %><BR>
�� Double : <%=dblNum %><BR>
�� Byte : <%=bytNum %><BR><BR>
<HR>
<%
strNum = "-1";

// �� String���� Integer������ ��ȯ 
intNum = Integer.parseInt(strNum);

// �� String���� Double������ ��ȯ
dblNum = Double.parseDouble(strNum);

// �� String���� Byte������ ��ȯ
bytNum = Byte.parseByte(strNum);
%>

<%-- ��ȯ ��� ��� --%>
String : <%=strNum %><BR>
�� Integer : <%=intNum %><BR>
�� Double : <%=dblNum %><BR>
�� Byte : <%=bytNum %><BR><BR>
<HR>
<%
strNum = "1.234";

// �� String���� Double������ ��ȯ
dblNum = Double.parseDouble(strNum);

// �� String���� Float������ ��ȯ
fltNum = Float.parseFloat(strNum);
%>

<%-- ��ȯ ��� ��� --%>
String : <%=strNum %><BR>
�� Double : <%=dblNum %><BR>
�� Float : <%=fltNum %><BR><BR>
<HR>
<%
strNum = "-1.234";
    
// �� String���� Double������ ��ȯ
dblNum = Double.parseDouble(strNum);

// �� String���� Float������ ��ȯ
fltNum = Float.parseFloat(strNum);
%>

<%-- ��ȯ ��� ��� --%>
String : <%=strNum %><BR>
�� Double : <%=dblNum %><BR>
�� Float : <%=fltNum %><BR>
<HR>
</BODY>
</HTML>
