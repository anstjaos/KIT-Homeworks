<%@ page language="java" contentType="text/html; charset=euc-kr" %>

<HTML>
<HEAD>
<TITLE> Quiz 4 - 클라이언트 정보 출력 </TITLE>
</HEAD>
<BODY>

<TABLE border=1>
<TR>
	<TD><B> Client & Server Information </B></TD>
    	<TD><B> 값 </B></TD>
</TR>

<% 
out.println ("<TR><TD>클라이언트 이름</TD><TD>" + request.getRemoteHost() + "</TD></TR>");
out.println ("<TR><TD>클라이언트 IP 주소</TD><TD>" + request.getRemoteAddr()+ "</TD></TR>");
out.println ("<TR><TD>클라이언트 URL 경로</TD><TD>" + request.getRequestURL()+ "</TD></TR>");
out.println ("<TR><TD>전송 방식</TD><TD>" + request.getMethod() + "</TD></TR>");
out.println ("<TR><TD>프로토콜 이름</TD><TD>" + request.getProtocol() + "</TD></TR>");
out.println ("<TR><TD>서버 이름</TD><TD>" + request.getServerName() + "</TD></TR>");
%>
</TABLE>

</BODY>
</HTML>
