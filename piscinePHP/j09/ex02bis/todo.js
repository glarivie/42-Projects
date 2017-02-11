/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   todo.js                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 09:50:36 by glarivie          #+#    #+#             */
/*   Updated: 2016/04/16 23:21:38 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

var todosUL = $('#todos'),
	newButton = $('#new'),
	cookie = document.cookie,
	todosList = [];

var displayElem = function(todosList) {
	$.each(todosList, function(index) {
		todosUL.append('<li><span class="before">☰</span><p id="' + index + '"></p><span class="after" id="close-' + index + '">✖</span></li>');
		$('#' + index).html(todosList[index]);
		$('#close-' + index).on('click', function() {
				if (confirm('Delete ' + todosList[index] + ' ?')) {
					todosList.splice(index, 1);
					$(this).closest('li').remove();
					document.cookie = JSON.stringify(todosList);
					console.log(document.cookie);
					// console.log(todosList);
				}
			});
	});
	return ;
};

newButton.on('click', function() {
	var todo = prompt('Add TODO');
	if (todo) {
		todosList.unshift(todo);
		document.cookie = JSON.stringify(todosList);
		if (todosUL.html())
			todosUL.empty();
		displayElem(todosList);
	}
});

if (cookie) {
	todosList = JSON.parse(document.cookie);
	displayElem(todosList);
} else {
	document.cookie = "";
	// console.log('Cookie not found');
}
