<%@ page import="JavaBean.Quiz8_Bean" contentType = "text/html; charset=euc-kr" %>
<jsp:useBean id="calc" scope="request" class="JavaBean.Quiz8_Bean" />

<%
int a1 = 55;
int a2 = 5;

calc.setValue(a1,a2); 
%>

<jsp:forward page="Quiz8_2.jsp" />