<%@ page contentType="text/html;charset=euc-kr" %>
<%@ page import = "java.net.URLDecoder" %>
<%@ page import = "java.net.URLEncoder" %>

<%
String id = request.getParameter("id");
String pass = request.getParameter("password");

String value = request.getHeader("Cookie");
out.println("Cookie: " + value + "<BR>");

if(value == null) {
	Cookie cookie1 = new Cookie("id",URLEncoder.encode(id));
	Cookie cookie2 = new Cookie("password", URLEncoder.encode(pass));

	cookie1.setMaxAge(60*10);
	cookie2.setMaxAge(60*10);

	response.addCookie(cookie1);
	response.addCookie(cookie2);

	out.print("쿠키를 설정합니다.");
	out.println("<LI>id: "+id+"</LI>");
	out.println("<LI>pass: "+pass+"</LI>");

} else{
	out.print("쿠키가 설정 되어있습니다.");
	
	Cookie[] cookies = request.getCookies();
	
	for(int i = 0; i < cookies.length; i++)
	{
		out.println("<LI>" + cookies[i].getName()+ " : " + URLDecoder.decode(cookies[i].getValue()) +"</LI>");
	}

}

%>
