<%@ page contentType="text/html;charset=euc-kr" %>

<HTML>
<HEAD>
<TITLE> Quiz 1 - 자료형 변환 </TITLE>
</HEAD>
<BODY>

<%
// 변수 선언
String strNum;
int intNum;
double dblNum;
float fltNum;
byte bytNum;
    
strNum = "1";

// ① String형을 Integer형으로 변환
intNum = Integer.parseInt(strNum);
    
// ② String형을 Double형으로 변환
dblNum = Double.parseDouble(strNum);
    
// ③ String형을 Byte형으로 변환
bytNum = Byte.parseByte(strNum);
%>

<%-- 변환 결과 출력 --%>
String : <%=strNum %><BR>
① Integer : <%=intNum %><BR>
② Double : <%=dblNum %><BR>
③ Byte : <%=bytNum %><BR><BR>
<HR>
<%
strNum = "-1";

// ④ String형을 Integer형으로 변환 
intNum = Integer.parseInt(strNum);

// ⑤ String형을 Double형으로 변환
dblNum = Double.parseDouble(strNum);

// ⑥ String형을 Byte형으로 변환
bytNum = Byte.parseByte(strNum);
%>

<%-- 변환 결과 출력 --%>
String : <%=strNum %><BR>
④ Integer : <%=intNum %><BR>
⑤ Double : <%=dblNum %><BR>
⑥ Byte : <%=bytNum %><BR><BR>
<HR>
<%
strNum = "1.234";

// ⑦ String형을 Double형으로 변환
dblNum = Double.parseDouble(strNum);

// ⑧ String형을 Float형으로 변환
fltNum = Float.parseFloat(strNum);
%>

<%-- 변환 결과 출력 --%>
String : <%=strNum %><BR>
⑦ Double : <%=dblNum %><BR>
⑧ Float : <%=fltNum %><BR><BR>
<HR>
<%
strNum = "-1.234";
    
// ⑨ String형을 Double형으로 변환
dblNum = Double.parseDouble(strNum);

// ⑩ String형을 Float형으로 변환
fltNum = Float.parseFloat(strNum);
%>

<%-- 변환 결과 출력 --%>
String : <%=strNum %><BR>
⑨ Double : <%=dblNum %><BR>
⑩ Float : <%=fltNum %><BR>
<HR>
</BODY>
</HTML>
