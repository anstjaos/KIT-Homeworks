<%@ page language="Java" contentType="text/html; charset=euc-kr" %>

<HTML>
<HEAD>
<TITLE> Quiz 6 - pageContext 객체 활용 </TITLE>
</HEAD>
<BODY>

<%
pageContext.getOut().println("서블릿 이름 : " + pageContext.getServletConfig().getServletName()+"<BR>"); 
ServletContext context = pageContext.getServletConfig().getServletContext(); 
out.println("서버 메이저 버전 : "+context.getMajorVersion() + "<BR>");

long lastTime = pageContext.getSession().getLastAccessedTime();
long createTime = pageContext.getSession().getCreationTime();
long useTime = (lastTime - createTime) / 60000;
%>

<%=useTime %>
초 동안 사이트에 접속되어 있습니다.

</BODY>
</HTML>