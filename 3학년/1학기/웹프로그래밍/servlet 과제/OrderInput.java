import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class OrderInput extends HttpServlet {
  public void service( HttpServletRequest req,
                                 HttpServletResponse res )
    throws ServletException, IOException {

      res.setContentType("text/html;charset=EUC-KR");

      PrintWriter out = res.getWriter( );
      out.println("<html><head><title>���� �ֹ�</title>");
      out.println("<script type=\"text/javascript\" src=\"submitCheck.js\"></script></head>");
      out.println("<body>");
      out.println("<h2>���� �ֹ��ϱ�</h2><hr>");
      out.println("<form method=post action=http://localhost:8080/myweb/OrderConfirm onSubmit=\"return create(this);\" target=\"w\">");
      out.println("<p><label>�� �̸�: <input name=\"custname\" placeholder=\"�̸��� �Է��ϼ���.\"></label></p>");
      out.println("<p><label>��ȭ ��ȣ: <input type=tel name=\"custtel\" placeholder=\"��ȭ��ȣ�� �Է��ϼ���.\"></label></p>");
      out.println("<p><label>���� �ּ�: <input type=email name=\"custemail\" placeholder=\"���� �ּҸ� �Է��ϼ���.\"></label></p>");
      out.println("<fieldset>");
      out.println("<legend>���� ũ�� ����</legend>");
      out.println("<label> <input type=radio name=\"size\" value=\"small\"> Small </label>");
      out.println("<label> <input type=radio name=\"size\" value=\"medium\"> Medium </label>");
      out.println("<label> <input type=radio name=\"size\" value=\"large\"> Large </label>");
      out.println("</fieldset>");
      out.println("<br> <fieldset>");
      out.println("<legend> ���� ���� ���� </legend>");
      out.println("<label> <input type=checkbox name=\"topping\" value=\"bacon\"> ������ </label>");
      out.println("<label> <input type=checkbox name=\"topping\" value=\"cheese\"> ġ�� </label>");
      out.println("<label> <input type=checkbox name=\"topping\" value=\"onion\"> ���� </label>");
      out.println("<label> <input type=checkbox name=\"topping\" value=\"mushroom\"> ���� </label>");
      out.println("</fieldset> <br>");
      out.println("<label>���ϴ� ��� �ð�: <input type=time min=\"11:00\" max=\"21:00\" step=\"900\" name=\"delivery\"></label><br>");
      out.println("<label>��޽� �䱸 ����: <textarea name=\"comments\" placeholder=\"��޽� �䱸������ �Է��ϼ���.\"></textarea></label>");
      out.println("<p><button>���� �ֹ��ϱ�</button></p>");
      out.println("</form>");
      out.println("</body>");
      out.println("</html>");
     
    }
}
