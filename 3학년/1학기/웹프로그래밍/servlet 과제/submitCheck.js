function isNull(obj, msg) {
	if(obj.value == "") {
		if(msg) {
			alert(msg);
		}
		obj.focus();
		return true;
	}
	return false;
}

function isChecked(checkArr) {
	for(i =0; i < checkArr.length;i++) {
		if(checkArr[i].checked == true) return true;
	}
	return false;
}


function create(form) {
	var arr_topping = document.getElementsByName("topping");
	var isToppingCheck =isChecked(arr_topping);
	
	var sizeArr = form.elements["size"];
	var isSizeCheck = isChecked(sizeArr);
   if(isNull(form.custname, "�̸��� �Է��ϼ���.")){
 	return false;
   }
   else if(isNull(form.custtel, "��ȭ��ȣ�� �Է��ϼ���.")){
 	return false;
   }
   else if(isNull(form.custemail, "������ �Է��ϼ���.")){
 	return false;
   }
   else if(!isSizeCheck){
	alert("����� �Է��ϼ���.");
 	return false;
   }
   else if(!isToppingCheck){
	alert("������ �Է��ϼ���.");
 	return false;
   }
   else if(isNull(form.delivery, "��� �ð��� �Է��ϼ���.")){
 	return false;
   }

   var win = open('','w','width=500,height=300');
   return true;
}
