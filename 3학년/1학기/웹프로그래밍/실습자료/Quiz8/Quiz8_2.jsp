<%@ page import="JavaBean.Quiz8_Bean" contentType = "text/html; charset=euc-kr" %>
<jsp:useBean id="calc" scope="request" class="JavaBean.Quiz8_Bean" />

<HTML>
<HEAD>
<TITLE> Quiz 8 - 빈즈를 활용한 사칙연산</TITLE>
</HEAD>
<BODY>

<% 
 out.print("더하기 : " + calc.getValue1() + " + " + calc.getValue2() + " = " + calc.getAdd() + "<br>");
 out.print("곱하기 : " + calc.getValue1() + " * " + calc.getValue2() + " = " + calc.getMelt()+ "<br>");
 out.print("빼기 : " + calc.getValue1() + " - " + calc.getValue2() + " = " + calc.getMinus()+ "<br>");
 out.print("나누기 : " + calc.getValue1() + " / " + calc.getValue2() + " = " + calc.getDiv() + "<br>");
%>

</BODY>
</HTML>