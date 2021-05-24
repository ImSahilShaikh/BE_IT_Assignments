<%@page contentType="text/html;charset=UTF-8"%>
<% request.setCharacterEncoding("UTF-8"); %>
<HTML>
<HEAD>
<TITLE>Result</TITLE>
</HEAD>
<BODY>
<H1>Result</H1>

<jsp:useBean id="sampleCalculatorProxyid" scope="session" class="DefaultNamespace.CalculatorProxy" />
<%
if (request.getParameter("endpoint") != null && request.getParameter("endpoint").length() > 0)
sampleCalculatorProxyid.setEndpoint(request.getParameter("endpoint"));
%>

<%
String method = request.getParameter("method");
int methodID = 0;
if (method == null) methodID = -1;

if(methodID != -1) methodID = Integer.parseInt(method);
boolean gotMethod = false;

try {
switch (methodID){ 
case 2:
        gotMethod = true;
        java.lang.String getEndpoint2mtemp = sampleCalculatorProxyid.getEndpoint();
if(getEndpoint2mtemp == null){
%>
<%=getEndpoint2mtemp %>
<%
}else{
        String tempResultreturnp3 = org.eclipse.jst.ws.util.JspUtils.markup(String.valueOf(getEndpoint2mtemp));
        %>
        <%= tempResultreturnp3 %>
        <%
}
break;
case 5:
        gotMethod = true;
        String endpoint_0id=  request.getParameter("endpoint8");
            java.lang.String endpoint_0idTemp = null;
        if(!endpoint_0id.equals("")){
         endpoint_0idTemp  = endpoint_0id;
        }
        sampleCalculatorProxyid.setEndpoint(endpoint_0idTemp);
break;
case 10:
        gotMethod = true;
        DefaultNamespace.Calculator getCalculator10mtemp = sampleCalculatorProxyid.getCalculator();
if(getCalculator10mtemp == null){
%>
<%=getCalculator10mtemp %>
<%
}else{
        if(getCalculator10mtemp!= null){
        String tempreturnp11 = getCalculator10mtemp.toString();
        %>
        <%=tempreturnp11%>
        <%
        }}
break;
case 13:
        gotMethod = true;
        String a_1id=  request.getParameter("a16");
        double a_1idTemp  = Double.parseDouble(a_1id);
        String b_2id=  request.getParameter("b18");
        double b_2idTemp  = Double.parseDouble(b_2id);
        double add13mtemp = sampleCalculatorProxyid.add(a_1idTemp,b_2idTemp);
        String tempResultreturnp14 = org.eclipse.jst.ws.util.JspUtils.markup(String.valueOf(add13mtemp));
        %>
        <%= tempResultreturnp14 %>
        <%
break;
case 20:
        gotMethod = true;
        String a_3id=  request.getParameter("a23");
        double a_3idTemp  = Double.parseDouble(a_3id);
        String b_4id=  request.getParameter("b25");
        double b_4idTemp  = Double.parseDouble(b_4id);
        double divide20mtemp = sampleCalculatorProxyid.divide(a_3idTemp,b_4idTemp);
        String tempResultreturnp21 = org.eclipse.jst.ws.util.JspUtils.markup(String.valueOf(divide20mtemp));
        %>
        <%= tempResultreturnp21 %>
        <%
break;
case 27:
        gotMethod = true;
        String a_5id=  request.getParameter("a30");
        double a_5idTemp  = Double.parseDouble(a_5id);
        String b_6id=  request.getParameter("b32");
        double b_6idTemp  = Double.parseDouble(b_6id);
        double multiply27mtemp = sampleCalculatorProxyid.multiply(a_5idTemp,b_6idTemp);
        String tempResultreturnp28 = org.eclipse.jst.ws.util.JspUtils.markup(String.valueOf(multiply27mtemp));
        %>
        <%= tempResultreturnp28 %>
        <%
break;
case 34:
        gotMethod = true;
        String a_7id=  request.getParameter("a37");
        double a_7idTemp  = Double.parseDouble(a_7id);
        String b_8id=  request.getParameter("b39");
        double b_8idTemp  = Double.parseDouble(b_8id);
        double subtract34mtemp = sampleCalculatorProxyid.subtract(a_7idTemp,b_8idTemp);
        String tempResultreturnp35 = org.eclipse.jst.ws.util.JspUtils.markup(String.valueOf(subtract34mtemp));
        %>
        <%= tempResultreturnp35 %>
        <%
break;
}
} catch (Exception e) { 
%>
Exception: <%= org.eclipse.jst.ws.util.JspUtils.markup(e.toString()) %>
Message: <%= org.eclipse.jst.ws.util.JspUtils.markup(e.getMessage()) %>
<%
return;
}
if(!gotMethod){
%>
result: N/A
<%
}
%>
</BODY>
</HTML>