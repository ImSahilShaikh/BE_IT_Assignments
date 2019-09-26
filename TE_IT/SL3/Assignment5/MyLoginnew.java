

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class MyLoginnew
 */
@WebServlet("/MyLoginnew")
public class MyLoginnew extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public MyLoginnew() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.getWriter().append("Served at: ").append(request.getContextPath());
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		response.setContentType("text/html");
		PrintWriter out = response.getWriter();
		String uname = request.getParameter("uname");
		String pass = request.getParameter("pass");

		try {
			Class.forName("org.mariadb.jdbc.Driver");
			Connection con = DriverManager.getConnection("jdbc:mariadb://localhost:3306/Demo", "Sahil", "Sahil@123");
			out.println("Connected");
			String query = "select password from accounts where name='" + uname + "'";
			Statement st = con.createStatement();
			ResultSet rs = st.executeQuery(query);

			if (rs.next()) {
				if (rs.getString("password").equals(pass)) {
					out.println("<script>alert('Access Granted')</script>");
					response.sendRedirect("success.jsp");
				} else {
					out.println("<script>alert('Invalid Crentials')</script>");
					response.sendRedirect("failure.jsp");
				}
			} else {
				out.println("<script>alert('No user Exists with Entered Username')</script>");
				response.sendRedirect("failure.jsp");

			}
			con.close();
			st.close();
			rs.close();
		} catch (Exception e) {
			out.println("Cant connect"+e.getMessage());
		}
	}
}
