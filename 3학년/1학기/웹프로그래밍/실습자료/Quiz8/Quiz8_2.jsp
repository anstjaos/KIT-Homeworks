<%@ page import="JavaBean.Quiz8_Bean" contentType = "text/html; charset=euc-kr" %>
<jsp:useBean id="calc" scope="request" class="JavaBean.Quiz8_Bean" />

<HTML>
<HEAD>
<TITLE> Quiz 8 - ��� Ȱ���� ��Ģ����</TITLE>
</HEAD>
<BODY>

<% 
 out.print("���ϱ� : " + calc.getValue1() + " + " + calc.getValue2() + " = " + calc.getAdd() + "<br>");
 out.print("���ϱ� : " + calc.getValue1() + " * " + calc.getValue2() + " = " + calc.getMelt()+ "<br>");
 out.print("���� : " + calc.getValue1() + " - " + calc.getValue2() + " = " + calc.getMinus()+ "<br>");
 out.print("������ : " + calc.getValue1() + " / " + calc.getValue2() + " = " + calc.getDiv() + "<br>");
%>

</BODY>
</HTML>