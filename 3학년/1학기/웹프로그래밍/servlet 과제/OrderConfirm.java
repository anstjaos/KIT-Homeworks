import java.io.*;
import java.util.Enumeration;
import javax.servlet.*;
import javax.servlet.http.*;

public class OrderConfirm extends HttpServlet {
	public void doPost(HttpServletRequest req, HttpServletResponse res)
		throws ServletException, IOException {

		res.setContentType("text/html;charset=KSC5601");
		PrintWriter out = res.getWriter();
		req.setCharacterEncoding("KSC5601");
		
		out.println("<html>");
		out.println("<head><title>Order Confirm</title></head>");
		out.println("<body>");
		
		out.println("<h1>주문 결과 확인</h1>");
		Enumeration e = req.getParameterNames();
		while (e.hasMoreElements()) {
			String name = (String) e.nextElement();
			String values[] = req.getParameterValues(name);
			if(values != null) {
				for(int i=0; i < values.length; i++) {
					out.print("<li>" + name + " : " + values[i]);
				}
			}
		}
		out.println("</body>");
		out.println("</html>");
		out.close();
	}	
}