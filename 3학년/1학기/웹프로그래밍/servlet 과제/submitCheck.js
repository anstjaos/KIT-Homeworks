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
   if(isNull(form.custname, "이름을 입력하세요.")){
 	return false;
   }
   else if(isNull(form.custtel, "전화번호를 입력하세요.")){
 	return false;
   }
   else if(isNull(form.custemail, "메일을 입력하세요.")){
 	return false;
   }
   else if(!isSizeCheck){
	alert("사이즈를 입력하세요.");
 	return false;
   }
   else if(!isToppingCheck){
	alert("토핑을 입력하세요.");
 	return false;
   }
   else if(isNull(form.delivery, "배달 시간을 입력하세요.")){
 	return false;
   }

   var win = open('','w','width=500,height=300');
   return true;
}
