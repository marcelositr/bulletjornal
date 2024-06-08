#!/bin/bash

# Define paths
CONFIG_DIR="$HOME/.bujo"
TODO_FILE="$CONFIG_DIR/todo.bujo"
DAILY_FILE="$CONFIG_DIR/daily.bujo"
BIN_DIR="$HOME/bin"
BUJO_SCRIPT="bujo"
NANORC_FILE="bujo.nanorc"
NANO_SYSTEM_DIR="/usr/share/nano"

# Function to display installation messages
show_message() {
    echo "=> $1"
    sleep 0.5
}

# Function to copy files and create directories
copy_files_and_create_dirs() {
    show_message "Creating $CONFIG_DIR directory"
    mkdir -p "$CONFIG_DIR"

    show_message "Copying $DAILY_FILE"
    cp daily.bujo "$DAILY_FILE"

    show_message "Copying $TODO_FILE"
    cp todo.bujo "$TODO_FILE"

    show_message "Copying $BUJO_SCRIPT to $BIN_DIR"
    mkdir -p "$BIN_DIR"
    cp bujo "$BIN_DIR"

    add_bin_to_path_in_bashrc
}

# Function to add bin directory to PATH in .bashrc
add_bin_to_path_in_bashrc() {
    show_message "Adding $BIN_DIR to PATH in .bashrc"
    echo 'if [ -d "$HOME/bin" ]; then' >> "$HOME/.bashrc"
    echo '    PATH="$HOME/bin:$PATH"' >> "$HOME/.bashrc"
    echo '    source "$HOME/.bashrc"' # Reload .bashrc
    echo 'fi' >> "$HOME/.bashrc"
}

# Function to copy nano config file to system
copy_nanorc_file() {
    show_message "Copying $NANORC_FILE to $NANO_SYSTEM_DIR"
    sudo cp "$NANORC_FILE" "$NANO_SYSTEM_DIR"
}

# Main installation process
main() {
    copy_files_and_create_dirs
    copy_nanorc_file
    echo "Installation completed successfully!"
}

# Execute main function
main
