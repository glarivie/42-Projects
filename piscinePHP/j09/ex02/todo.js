/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   todo.js                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 09:50:07 by glarivie          #+#    #+#             */
/*   Updated: 2016/04/16 23:21:51 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

var todosUL = document.getElementById('todos'),
	newButton = document.getElementById('new'),
	cookie = document.cookie,
	todosList = [];

var clearList = function(todosUL) {
	while (todosUL.firstChild) {
	    todosUL.removeChild(todosUL.firstChild);
	}
	return ;
};

var displayElem = function(todosList) {
	todosList.forEach(function(index) {
		var newListElement = document.createElement('li'),
			currentId = todosList.indexOf(index);
		newListElement.innerHTML = '<span class="before">☰</span><p id="' + index + '"></p><span class="after" id="' + currentId + '">✖</span>';
		todosUL.appendChild(newListElement);
		document.getElementById(index).innerHTML = index;
		document.getElementById(currentId).addEventListener('click', function(e) {
				if (confirm('Delete ' + index + ' ?')) {
					todosList.splice(todosList.indexOf(index), 1);
					todosUL.removeChild(e.target.parentElement);
					document.cookie = JSON.stringify(todosList);
					console.log(document.cookie);
					// console.log(todosList);
				}
			},false);
	});
	return ;
};

newButton.addEventListener('click', function(e) {
	var todo = prompt('Add TODO');
	if (todo) {
		todosList.unshift(todo);
		document.cookie = JSON.stringify(todosList);
		if (todosUL.innerHTML)
			clearList(todosUL);
		displayElem(todosList);
	}
}, false);

if (cookie) {
	todosList = JSON.parse(document.cookie);
	displayElem(todosList);
} else {
	document.cookie = "";
	// console.log('Cookie not found');
}
