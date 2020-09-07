var text_input=document.getElementById("text");
document.querySelector("#submit").addEventListener("click",printList);
function printList(){
	if(text_input.value!=""){
		var list_value=text_input.value;  //list value
		var list_item=document.createElement("p");  //Creating a p element
		var list_check_btn=document.createElement("i"); //Creating check button
		var list_delete_btn=document.createElement("i"); //Creating delete button

		document.querySelector("div").appendChild(list_item);  //put p inside div element
		list_item.textContent=list_value;//change the content of p element
		list_item.appendChild(list_check_btn);
		var span_space=document.createElement("span");
		span_space.textContent=" ";
		list_item.appendChild(span_space);
		list_item.appendChild(list_delete_btn);
		list_check_btn.classList.add("fa-check");
		list_check_btn.classList.add("fas");
		list_check_btn.classList.add("fa-xs");
		list_check_btn.classList.add("icon2");
		list_delete_btn.classList.add("fa-trash-alt");
		list_delete_btn.classList.add("far");
		list_delete_btn.classList.add("fa-xs");
		list_delete_btn.classList.add("icon1");
		list_item.classList.add("text_items");
		text_input.value="";  //Just Clearing the input field

		//deleting and checking
		list_delete_btn.addEventListener("click",deleteTask);
		list_check_btn.addEventListener("click",checkTask);

		function deleteTask(x){
			x.target.parentElement.remove();
		}
		function checkTask(x){
			x.target.parentElement.classList.toggle("linedraw");
		}
	}
}

