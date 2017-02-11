/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   todo.js                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 09:51:06 by glarivie          #+#    #+#             */
/*   Updated: 2016/04/16 23:21:26 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

var todosUL = $('#todos'),
	newButton = $('#new'),
	todosList = {
		'todos' : [],
	};

var getTodos = function() {
	$.get('select.php', function(data) {
		if (data) {
			if (todosUL.html())
				todosUL.empty();
			todosList = ($.parseJSON(data));
			displayElem(todosList);
		}
	});
};

var deleteTodo = function(todoId) {
	for (var index = 0; index < todosList.todos.length; index++) {
		if (todosList.todos[index].id === todoId)
			todosList.todos.splice(index, 1);
	}
	$.post('delete.php', JSON.stringify(todosList));
};

var displayElem = function(todosList) {
	$.each(todosList.todos, function(index) {
		var currentID = todosList.todos[index].id,
			currentTodo = todosList.todos[index].todo;
		todosUL.append('<li><span class="before">☰</span><p>' + currentTodo + '</p><span class="after" id="close-' + currentID + '">✖</span></li>');
		$('#close-' + currentID).on('click', function() {
				if (confirm('Delete ' + currentTodo + ' ?')) {
					deleteTodo(currentID);
					$(this).closest('li').remove();
				}
			});
	});
	return ;
};

var uniqId = function() {
	return Math.round(new Date().getTime() + (Math.random() * 100));
};

newButton.on('click', function() {
	var todo = {
		'id' : 0,
		'todo' : '',
	};
	todo.todo = prompt('Add TODO');
	if (todo.todo) {
		todo.id = uniqId();
		todosList.todos.unshift(todo);
		$.post('insert.php', JSON.stringify(todosList));
		getTodos();
	}
});

$('document').ready(function() {
	getTodos();
});
