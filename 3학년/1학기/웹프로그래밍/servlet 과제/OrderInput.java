import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class OrderInput extends HttpServlet {
  public void service( HttpServletRequest req,
                                 HttpServletResponse res )
    throws ServletException, IOException {

      res.setContentType("text/html;charset=EUC-KR");

      PrintWriter out = res.getWriter( );
      out.println("<html><head><title>피자 주문</title>");
      out.println("<script type=\"text/javascript\" src=\"submitCheck.js\"></script></head>");
      out.println("<body>");
      out.println("<h2>피자 주문하기</h2><hr>");
      out.println("<form method=post action=http://localhost:8080/myweb/OrderConfirm onSubmit=\"return create(this);\" target=\"w\">");
      out.println("<p><label>고객 이름: <input name=\"custname\" placeholder=\"이름을 입력하세요.\"></label></p>");
      out.println("<p><label>전화 번호: <input type=tel name=\"custtel\" placeholder=\"전화번호를 입력하세요.\"></label></p>");
      out.println("<p><label>메일 주소: <input type=email name=\"custemail\" placeholder=\"메일 주소를 입력하세요.\"></label></p>");
      out.println("<fieldset>");
      out.println("<legend>피자 크기 선택</legend>");
      out.println("<label> <input type=radio name=\"size\" value=\"small\"> Small </label>");
      out.println("<label> <input type=radio name=\"size\" value=\"medium\"> Medium </label>");
      out.println("<label> <input type=radio name=\"size\" value=\"large\"> Large </label>");
      out.println("</fieldset>");
      out.println("<br> <fieldset>");
      out.println("<legend> 피자 토핑 고르기 </legend>");
      out.println("<label> <input type=checkbox name=\"topping\" value=\"bacon\"> 베이컨 </label>");
      out.println("<label> <input type=checkbox name=\"topping\" value=\"cheese\"> 치즈 </label>");
      out.println("<label> <input type=checkbox name=\"topping\" value=\"onion\"> 양파 </label>");
      out.println("<label> <input type=checkbox name=\"topping\" value=\"mushroom\"> 버섯 </label>");
      out.println("</fieldset> <br>");
      out.println("<label>원하는 배달 시간: <input type=time min=\"11:00\" max=\"21:00\" step=\"900\" name=\"delivery\"></label><br>");
      out.println("<label>배달시 요구 사항: <textarea name=\"comments\" placeholder=\"배달시 요구사항을 입력하세요.\"></textarea></label>");
      out.println("<p><button>피자 주문하기</button></p>");
      out.println("</form>");
      out.println("</body>");
      out.println("</html>");
     
    }
}
