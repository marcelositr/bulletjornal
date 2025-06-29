#!/bin/bash

# Define user-specific paths
CONFIG_DIR="$HOME/.bujo"
TODO_FILE="$CONFIG_DIR/todo.bujo"
DAILY_FILE="$CONFIG_DIR/daily.bujo"

# Define system-wide standard paths
BIN_DIR="/usr/local/bin"
NANO_SYSTEM_DIR="/usr/share/nano"

# Files to be installed
BUJO_SCRIPT="bujo"
NANORC_FILE="bujo.nanorc"

# Function to display installation messages
show_message() {
    echo "=> $1"
}

# Main installation process
main() {
    show_message "This script will install 'bujo' to standard system locations."
    show_message "You will be prompted for your password for 'sudo' commands."
    echo

    # Create user configuration directory
    show_message "Creating configuration directory at $CONFIG_DIR..."
    mkdir -p "$CONFIG_DIR"

    # Copy initial journal files, but do not overwrite if they exist
    show_message "Copying initial journal files..."
    if [ ! -f "$DAILY_FILE" ]; then
        cp daily.bujo "$DAILY_FILE"
    else
        show_message "Skipping: $DAILY_FILE already exists."
    fi

    if [ ! -f "$TODO_FILE" ]; then
        cp todo.bujo "$TODO_FILE"
    else
        show_message "Skipping: $TODO_FILE already exists."
    fi

    # Install the main script to the standard binary location
    show_message "Installing '$BUJO_SCRIPT' to $BIN_DIR..."
    sudo cp "$BUJO_SCRIPT" "$BIN_DIR/$BUJO_SCRIPT"

    # Make the script executable
    show_message "Making '$BUJO_SCRIPT' executable..."
    sudo chmod +x "$BIN_DIR/$BUJO_SCRIPT"

    # Install the nano syntax highlighting file
    show_message "Installing nano syntax file '$NANORC_FILE' to $NANO_SYSTEM_DIR..."
    sudo cp "$NANORC_FILE" "$NANO_SYSTEM_DIR/$NANORC_FILE"

    echo
    show_message "Installation completed successfully!"
    show_message "You can now run the 'bujo' command from anywhere in your terminal."
}

# Execute main function
main
