<%@ page language="Java" contentType="text/html; charset=euc-kr" %>

<HTML>
<HEAD>
<TITLE> Quiz 6 - pageContext ��ü Ȱ�� </TITLE>
</HEAD>
<BODY>

<%
pageContext.getOut().println("���� �̸� : " + pageContext.getServletConfig().getServletName()+"<BR>"); 
ServletContext context = pageContext.getServletConfig().getServletContext(); 
out.println("���� ������ ���� : "+context.getMajorVersion() + "<BR>");

long lastTime = pageContext.getSession().getLastAccessedTime();
long createTime = pageContext.getSession().getCreationTime();
long useTime = (lastTime - createTime) / 60000;
%>

<%=useTime %>
�� ���� ����Ʈ�� ���ӵǾ� �ֽ��ϴ�.

</BODY>
</HTML>