<%@ page language="java" contentType="text/html; charset=euc-kr" %>

<HTML>
<HEAD>
<TITLE> Quiz 5 - 출력 버퍼 제어 </TITLE>
</HEAD>
<BODY>

<%
out.println("1고객님께서는 본 사이트에서 가방을 선택 하셨습니다.<BR>");
out.println("2고객님께서는 본 사이트에서 청바지를 선택 하셨습니다.<BR>");
out.println("3고객님께서는 본 사이트에서 양말을 선택 하셨습니다.<BR>");
out.println("4고객님께서는 본 사이트에서 신발을 선택 하셨습니다.<BR>");
out.close();
out.println("5고객님께서는 본 사이트에서 mp3를 선택 하셨습니다.<BR>");
out.println("6고객님께서는 본 사이트에서 CD를 선택 하셨습니다.<BR>");

%>

</BODY>
</HTML>
